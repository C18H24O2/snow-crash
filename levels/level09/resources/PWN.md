# flag09

This level provides us with a simple executable that does a simple string shifting algorithm, and prints the result.

The password is hidden in the `token` file, and we need to guess that the file has already been put through this algorithm.

To get the password, we can reverse the algorithm (see `reverse.py`) and feed the `token` file to it.

`./reverse.py < token`

This will give us the password of the `flag09` account.
