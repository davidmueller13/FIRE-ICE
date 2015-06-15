GCOV_PROFILE := y
ccflags-y += -Idrivers/video/tegra/host
ccflags-y += -Werror

# start of strict-aliasing fix
CFLAGS_tsec.o  = -fno-strict-aliasing

nvhost-tsec-objs  = \
	tsec.o

obj-$(CONFIG_TEGRA_GRHOST) += nvhost-tsec.o
