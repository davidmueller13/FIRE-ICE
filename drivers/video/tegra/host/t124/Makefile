GCOV_PROFILE := y
ccflags-y += -Idrivers/video/tegra/host
ccflags-y += -Idrivers/video/tegra/camera
ccflags-y += -Wno-multichar
ccflags-y += -Werror

# start of strict-aliasing fix
CFLAGS_t124.o  = -fno-strict-aliasing

nvhost-t124-objs  = \
	t124.o

obj-$(CONFIG_TEGRA_GRHOST) += nvhost-t124.o
