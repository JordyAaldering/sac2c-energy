#include <unistd.h>
#include "rapl_energy_c.h"

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
