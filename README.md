# Movav

Implementation of a moving average filter for use in embedded applications such as firmware for PIC or AVR micro-controllers. Implements
* Choice of window size
* Window size up to 256 samples (depending on the used MCU, this could be more than the available memory. Be careful!)

The library allocates memory for a buffer which size is the window size.

# Examples

The project contains simple tests to demonstrate the features of the library. A makefile is provided so you can build the project  directly from the console.

```
make
```

The program performs a series of simple tests. You can modify these tests directly in the `tests.c` file.

## Authors

* **Emile Décosterd** - *Initial work* - [emiledecosterd](https://github.com/emiledecosterd)

See also the list of [contributors](https://github.com/emiledecosterd/movav/graphs/contributors) who participated in this project.

## License

This project is licensed under the GNU General Public License - see the [LICENSE.md](LICENSE.md) file for details
