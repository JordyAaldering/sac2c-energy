# For now this is tailored to my specific setup; sorry about that
all:
	cc -std=c99 -c -o src/rapl_energy.o src/rapl_energy.c
	../sac2c/build_d/sac2c_d -v0 Energy.sac
	../sac2c/build_d/sac2c_d -v0 -noprelude test.sac
