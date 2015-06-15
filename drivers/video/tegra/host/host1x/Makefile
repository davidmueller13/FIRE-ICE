GCOV_PROFILE := y
ccflags-y += -Idrivers/video/tegra/host
ccflags-y += -Werror

# start of strict-aliasing fix
CFLAGS_host1x.o = -fno-strict-aliasing

nvhost-host1x-objs  = \
	host1x.o

obj-$(CONFIG_TEGRA_GRHOST) += nvhost-host1x.o
