/*
 * Based on arch/arm/include/asm/tlbflush.h
 *
 * Copyright (C) 1999-2003 Russell King
 * Copyright (C) 2012 ARM Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __ASM_TLBFLUSH_H
#define __ASM_TLBFLUSH_H

#ifndef __ASSEMBLY__

#include <linux/sched.h>
#include <asm/cputype.h>

extern void __cpu_flush_user_tlb_range(unsigned long, unsigned long, struct vm_area_struct *);
extern void __local_cpu_flush_user_tlb_range(unsigned long, unsigned long, struct vm_area_struct *);
extern void __cpu_flush_kern_tlb_range(unsigned long, unsigned long);

extern struct cpu_tlb_fns cpu_tlb;

#define FLUSH_TLB_ALL_THRESHOLD (PAGE_SIZE * 128)

/*
 *	TLB Management
 *	==============
 *
 *	The arch/arm64/mm/tlb.S files implement these methods.
 *
 *	The TLB specific code is expected to perform whatever tests it needs
 *	to determine if it should invalidate the TLB for each call.  Start
 *	addresses are inclusive and end addresses are exclusive; it is safe to
 *	round these addresses down.
 *
 *	flush_tlb_all()
 *
 *		Invalidate the entire TLB.
 *
 *	flush_tlb_mm(mm)
 *
 *		Invalidate all TLB entries in a particular address space.
 *		- mm	- mm_struct describing address space
 *
 *	flush_tlb_range(mm,start,end)
 *
 *		Invalidate a range of TLB entries in the specified address
 *		space.
 *		- mm	- mm_struct describing address space
 *		- start - start address (may not be aligned)
 *		- end	- end address (exclusive, may not be aligned)
 *
 *	flush_tlb_page(vaddr,vma)
 *
 *		Invalidate the specified page in the specified address range.
 *		- vaddr - virtual address (may not be aligned)
 *		- vma	- vma_struct describing address range
 *
 *	flush_kern_tlb_page(kaddr)
 *
 *		Invalidate the TLB entry for the specified page.  The address
 *		will be in the kernels virtual memory space.  Current uses
 *		only require the D-TLB to be invalidated.
 *		- kaddr - Kernel virtual memory address
 */
static inline void flush_tlb_all(void)
{
	dsb();
	asm("tlbi	vmalle1is");
	dsb();
	isb();
}

static inline void local_flush_tlb_all(void)
{
	dsb();
	asm("tlbi	vmalle1");
	dsb();
	isb();
}

static inline void flush_tlb_mm(struct mm_struct *mm)
{
	unsigned long asid = (unsigned long)ASID(mm) << 48;

	preempt_disable();
	dsb();
	if (cpumask_equal(mm_cpumask(mm), cpumask_of(smp_processor_id())))
		asm("tlbi	aside1, %0" : : "r" (asid));
	else
		asm("tlbi	aside1is, %0" : : "r" (asid));
	dsb();
	preempt_enable();
}

static inline void flush_tlb_page(struct vm_area_struct *vma,
				  unsigned long uaddr)
{
	struct mm_struct *mm = vma->vm_mm;
	unsigned long addr = uaddr >> 12 | ((unsigned long)ASID(mm) << 48);

	preempt_disable();
	dsb();
	if (cpumask_equal(mm_cpumask(mm), cpumask_of(smp_processor_id())))
		asm("tlbi	vae1, %0" : : "r" (addr));
	else
		asm("tlbi	vae1is, %0" : : "r" (addr));
	dsb();
	preempt_enable();
}

static inline void flush_tlb_range(struct vm_area_struct *vma,
					unsigned long start, unsigned long end)
{
	struct mm_struct *mm = vma->vm_mm;

	preempt_disable();
	if (cpumask_equal(mm_cpumask(mm), cpumask_of(smp_processor_id()))) {
		if (end - start > FLUSH_TLB_ALL_THRESHOLD)
			local_flush_tlb_all();
		else
			__local_cpu_flush_user_tlb_range(start,end,vma);
	} else {
		if (end - start > FLUSH_TLB_ALL_THRESHOLD)
			flush_tlb_all();
		else
			__cpu_flush_user_tlb_range(start,end,vma);
	}
	preempt_enable();
}

static inline void flush_tlb_kernel_range(unsigned long start,
					unsigned long end)
{
	if (end - start > FLUSH_TLB_ALL_THRESHOLD)
		flush_tlb_all();
	else
		__cpu_flush_kern_tlb_range(start, end);
}

/*
 * On AArch64, the cache coherency is handled via the set_pte_at() function.
 */
static inline void update_mmu_cache(struct vm_area_struct *vma,
				    unsigned long addr, pte_t *ptep)
{
	/*
	 * set_pte() does not have a DSB, so make sure that the page table
	 * write is visible.
	 */
	dsb();
}

#endif

#endif
