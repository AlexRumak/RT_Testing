# Sleep Based Sequencer

Tuning did not work on CPU core 3, so we isolated the core by updating 
`/boot/firmware/cmdline.txt` on our rasppi to include `isolcpus=1-3`, and
then rebooted our rasppi.