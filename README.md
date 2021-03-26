# custom-ostream
Meant to function as a custom ostream for CSCE 410 at Texas A&amp;M

## To run locally
You will need `git`, `make` (GNU Make), and `g++` (or some other compiler; you will need to edit the `Makefile`):
```sh
git clone https://github.com/pulchroxloom/custom-ostream.git && \
cd custom-ostream && \
make run && \
echo "Successfully Installed"
```
You can now tweak the [`main.cpp`](main.cpp) file to test various output aspects. It should behave very similarly to the `std::ostream` objects `std::cout` and `std::cerr`. Color changing from `iomanip` does not work in the test environment and is instead a no-op. Also, the `dvb::cout` must be flushed before the program terminates, or there will be no output. Remember that `dvb::endl` is a flushing operation. `dvb::setforeground`, `dvb::setbackground`, and `dvb::setcolor` are also flushing operations.

## Description
The standard streams `std::cout`, `std::cerr`, et al. are a handy and valuable feature in which C++ developers have general proficiency. When developing an operating system (as is done in CSCE 410 at Texas A&amp;M University), it can help print during development. Printing can help one to find and fix issues and to inform the user of the program actions.

At Texas A&amp;M University, [Dr. Bettati](https://engineering.tamu.edu/cse/profiles/rbettati.html) has written a `console.H` file, which can permit some simple unformatted and unbuffered printing. This is a useful tool and works very well, however, its interface is unknown to many of the C++ proficient students and its procedure calls are sometimes clunky.

Therefore, the *custom-ostream* was born, a project by Dante Barbieri to permit using the standard streams (or an analogous structure) in the minimal environment used in CSCE 410. The big problem is that the Operating System has no virtual memory and cannot allocate until much later into the course. Printing early on in the class and during the development of virtual memory is important. Therefore, the standard streams had to be rewritten, and so they have been. These streams dynamically allocate no memory, which means that they are interestingly constrained only to print up to the maximum value of Unsigned Short characters (65535) before a flush. This is unlikely to be a problem, especially as `std::endl` is notoriously overused, implying that if anything, students flush too frequently.

Because of the nature of the compiler and virtual machine system in the course at the time of development, the `dvb::ostream` maintains compatibility with `c++98` though this could be updated without too much work. Some `c++11` features such as `std::hexfloat` have been implemented in the form of `dvb::hexfloat`.

## How can I use this in 410?
Download the `lib` folder and place it with your code, instead of including `console.H` in your `kernel.C` or other program files, include `lib/iostream.hpp` and possibly `lib/iomanip.hpp` should you want it. You can now use `dvb::cout` and `dvb::cerr` along with `dvb::endl` to your heart's content. Note, if you are failing to compile, you will need to add the following two functions to `console.H`:
```cpp
static unsigned char get_ForeColor() {
    return (unsigned char)(attrib & 0xf);
}

static unsigned char get_BackColor() {
    return (unsigned char)((attrib & 0xf0) >> 4);
}
```

## How can I look up information about this?
It was designed using the information on [cppreference](https://cppreference.com), so you could look up the classname you are using on that website to learn about its functions. Generally everything there should be here except for `streambuf` which is notoriously minimized and also anything to do with `input` is unlikely to be here as the primary purpose was printing. If someone opens a PR for the `input` side of things, I'll definitely consider adding it.

## How can I contribute?
Just fork this repo and make any changes you like, create a Pull Request and maybe send me an email at [dante@barbieri.dev](mailto::dante@barbieri.dev).

## License
The implementation is similar in many ways to the `GNU` implementation which was used as reference and is therefore licensed under the `GPL`. There is technically a restraint that this code cannot be used in proprietary applications meaning that the students must develop their operating systems to be open source accessible by the professor and teaching team on a version control system such as GitHub.
