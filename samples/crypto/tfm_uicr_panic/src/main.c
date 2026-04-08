#include <stddef.h>
#include <stdint.h>

#include <nrfx.h>
#include <tfm_ioctl_core_api.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define UICR_OTP_ADDR (NRF_UICR_S_BASE + offsetof(NRF_UICR_Type, OTP))

int main(void)
{
    uint32_t otp_words[2] = {0};
    uint32_t result = UINT32_MAX;
    enum tfm_platform_err_t err;

    printk("repro booted\n");

    err = tfm_platform_mem_read(otp_words, UICR_OTP_ADDR, sizeof(otp_words), &result);
    printk("otp-read err=%d result=%u word0=%08x word1=%08x\n",
           (int)err, result, otp_words[0], otp_words[1]);

    printk("about to panic...\n");
    k_panic();

    return 0;
}
