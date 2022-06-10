# Linux Misc driver Boilerplate
Linux Misc driver Boilerplate (LMB) is a very lightweight kernel module boilerplate for kernel development/testing.

Currently only tested on kernel versions: 5.3.0, 5.4.0, 5.18.1.

## Usage
To build the kernel module, simply run:

``` sh
$ make
```

By default it builds against the running kernel, if you want to change this adjust `KDIR` in `Makefile`.

You can then load the kernel module by running:

``` sh
$ sudo insmod lmb.ko
```

You should then be able to see `/dev/lmb_driver` if everything worked correctly; check `dmesg` and look for the `[LMB]` prefix for logging information. Note the device will be r/w for root only usually.

### Tests
To build the tests, just run:

``` sh
make test
```


