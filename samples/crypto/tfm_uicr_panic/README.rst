TF-M UICR Panic Repro
#####################

Minimal repro for the nRF91 TF-M UICR read issue.

Behavior:

* Reads two words from ``UICR.OTP`` via ``tfm_platform_mem_read()``
* Prints the result
* Calls ``k_panic()``

Target:

* ``nrf9160dk/nrf9160/ns``

Build:

.. code-block:: console

   west build --sysbuild -b nrf9160dk/nrf9160/ns -d build-tfm-uicr-panic ncs/nrf/samples/crypto/tfm_uicr_panic
