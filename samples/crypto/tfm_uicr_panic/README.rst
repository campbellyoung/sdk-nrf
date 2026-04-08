TF-M UICR Panic Repro
#####################

Minimal repro for the nRF91 TF-M UICR read issue. It shows difference between current and patched version in https://github.com/campbellyoung/nrfx/tree/nrfx-uicr-tfm-fix

All this example does is:

* Reads two words from ``UICR.OTP`` via ``tfm_platform_mem_read()``
* Prints the result
* Calls ``k_panic()``

Without nrfx patch:

Device will HardFault and seemingly hang

e.g..

.. code-block:: text

   *** Booting nRF Connect SDK v3.2.1-d8887f6f32df ***
   *** Using Zephyr OS v4.2.99-ec78104f1569 ***
   repro booted
   otp-read err=0 result=0 word0=ffffffff word1=ffffffff
   about to panic...


With the patch:

Panics as normal

.. code-block:: text

   *** Booting nRF Connect SDK v3.2.1-d8887f6f32df ***
   *** Using Zephyr OS v4.2.99-ec78104f1569 ***
   repro booted
   otp-read err=0 result=0 word0=ffffffff word1=ffffffff
   about to panic...
   r0/a1:  0x00000004  r1/a2:  0x0000f2df  r2/a3:  0x00000001
   r3/a4:  0x00000004 r12/ip:  0x00000000 r14/lr:  0x0000845d
    xpsr:  0x21000000
   Faulting instruction address (r15/pc): 0x0000846a


Target:

* ``nrf9160dk/nrf9160/ns``

Build:

.. code-block:: console

   west build --sysbuild -b nrf9160dk/nrf9160/ns -d build-tfm-uicr-panic ncs/nrf/samples/crypto/tfm_uicr_panic
