
GCOV_PROFILE := y
ccflags-y += -Idrivers/devfreq
ccflags-y += -Wno-multichar
ccflags-y += -Werror


# strict-aliasing fix
CFLAGS_gk20a.o = -fno-strict-aliasing
CFLAGS_as_gk20a.o = -fno-strict-aliasing
CFLAGS_ctrl_gk20a.o = -fno-strict-aliasing
CFLAGS_fifo_gk20a.o = -fno-strict-aliasing
CFLAGS_channel_gk20a.o = -fno-strict-aliasing
CFLAGS_channel_sync_gk20a.o = -fno-strict-aliasing
CFLAGS_debug_gk20a.o = -fno-strict-aliasing
CFLAGS_dbg_gpu_gk20a.o = -fno-strict-aliasing
CFLAGS_regops_gk20a.o  = -fno-strict-aliasing
CFLAGS_gr_gk20a.o = -fno-strict-aliasing
CFLAGS_kind_gk20a.o = -fno-strict-aliasing
CFLAGS_mm_gk20a.o = -fno-strict-aliasing
CFLAGS_pmu_gk20a.o = -fno-strict-aliasing
CFLAGS_priv_ring_gk20a.o = -fno-strict-aliasing
CFLAGS_clk_gk20a.o = -fno-strict-aliasing
CFLAGS_therm_gk20a.o = -fno-strict-aliasing
CFLAGS_gr_ctx_gk20a_sim.o = -fno-strict-aliasing
CFLAGS_gr_ctx_gk20a.o = -fno-strict-aliasing
CFLAGS_gk20a_gating_reglist.o = -fno-strict-aliasing
CFLAGS_gk20a_scale.o = -fno-strict-aliasing
CFLAGS_gk20a_sysfs.o = -fno-strict-aliasing
CFLAGS_ltc_gk20a.o = -fno-strict-aliasing
CFLAGS_fb_gk20a.o = -fno-strict-aliasing
CFLAGS_hal.o = -fno-strict-aliasing
CFLAGS_hal_gk20a.o = -fno-strict-aliasing
CFLAGS_gk20a_allocator.o = -fno-strict-aliasing
CFLAGS_platform_gk20a_generic.o = -fno-strict-aliasing
CFLAGS_platform_gk20a_tegra.o  = -fno-strict-aliasing

nvgpu-y := \
	gk20a.o \
	as_gk20a.o \
	ctrl_gk20a.o \
	fifo_gk20a.o \
	channel_gk20a.o \
	channel_sync_gk20a.o \
	debug_gk20a.o \
	dbg_gpu_gk20a.o \
	regops_gk20a.o \
	gr_gk20a.o \
	kind_gk20a.o \
	mm_gk20a.o \
	pmu_gk20a.o \
	priv_ring_gk20a.o \
	clk_gk20a.o \
	therm_gk20a.o \
	gr_ctx_gk20a_sim.o \
	gr_ctx_gk20a.o \
	gk20a_gating_reglist.o \
	gk20a_scale.o \
	gk20a_sysfs.o \
	ltc_gk20a.o \
	fb_gk20a.o \
	hal.o \
	hal_gk20a.o \
	gk20a_allocator.o \
	platform_gk20a_generic.o
nvgpu-$(CONFIG_TEGRA_GK20A) += platform_gk20a_tegra.o

obj-$(CONFIG_GK20A) := nvgpu.o
