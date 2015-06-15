GCOV_PROFILE := y
ccflags-y += -Idrivers/video/tegra/host
ccflags-y += -Idrivers/video/tegra/camera
ccflags-y += -Werror

# start of strict-aliasing fix
CFLAGS_isp.o = -fno-strict-aliasing

nvhost-isp-objs  = \
		isp.o

obj-$(CONFIG_TEGRA_GRHOST) += nvhost-isp.o
