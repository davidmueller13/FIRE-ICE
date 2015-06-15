GCOV_PROFILE := y
ccflags-y += -Idrivers/video/tegra/host
ccflags-y += -Idrivers/video/tegra/camera
ccflags-y += -Werror

# start of strict-aliasing fix
CFLAGS_vi_irq.o  = -fno-strict-aliasing
CFLAGS_tegra_vi.o  = -fno-strict-aliasing
CFLAGS_vi.o  = -fno-strict-aliasing

obj-y += vi_irq.o
obj-y += tegra_vi.o

nvhost-vi-objs = \
		vi.o \

obj-$(CONFIG_TEGRA_GRHOST_VI) += nvhost-vi.o
