#include <unistd.h>
#include "rapl_energy_c.h"

static void *amd_ptr, *amd_elapsed_ptr;
static void *intel_ptr, *intel_elapsed_ptr;

void energy_start()
{
    rapl_amd_start(&amd_ptr);
    rapl_intel_start(&intel_ptr);
}

void energy_stop()
{
    sleep(1);

    rapl_amd_stop(amd_ptr, &amd_elapsed_ptr);
    rapl_intel_stop(intel_ptr, &intel_elapsed_ptr);
}

void energy_print()
{
    rapl_print(amd_elapsed_ptr);
    rapl_print(intel_elapsed_ptr);
}

void energy_free()
{
    rapl_amd_free(amd_ptr, amd_elapsed_ptr);
    rapl_intel_free(intel_ptr, intel_elapsed_ptr);
}
