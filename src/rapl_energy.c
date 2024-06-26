#include<unistd.h>

extern const int rapl_amd_start(void **rapl_ptr);
extern const int rapl_amd_stop(void *rapl_ptr, void **elapsed_ptr);
extern const int rapl_intel_start(void **rapl_ptr);
extern const int rapl_intel_stop(void *rapl_ptr, void **elapsed_ptr);
extern const int rapl_print(void *elapsed_ptr);

// gcc -std=c99 -c -o src/rapl_energy.o src/rapl_energy.c src/librapl_energy_c.a

static void *amd_ptr, *amd_elapsed_ptr;
static void *intel_ptr, *intel_elapsed_ptr;

void start()
{
    rapl_amd_start(&amd_ptr);
    rapl_intel_start(&intel_ptr);
}

void stop()
{
    sleep(1);

    rapl_amd_stop(amd_ptr, &amd_elapsed_ptr);
    rapl_intel_stop(intel_ptr, &intel_elapsed_ptr);
}

void print()
{
    rapl_print(amd_elapsed_ptr);
    rapl_print(intel_elapsed_ptr);
}
