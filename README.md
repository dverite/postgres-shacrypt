## postgres-shacrypt

A PostgreSQL extension to generate SHA256-CRYPT and SHA512-CRYPT password hashes.  

See [https://www.akkadia.org/drepper/SHA-crypt.txt](https://www.akkadia.org/drepper/SHA-crypt.txt) for the specification and upstream code by Ulrich Drepper.


## Usage

     =# CREATE EXTENSION shacrypt;

     =# select sha256_crypt('clearpassword', 'somesalt');
			   sha256_crypt                       
     ---------------------------------------------------------
      $5$somesalt$l3SlbI688JBlRS9RWFC1EwZLNJqfQKcrF3yhcbc7ffA

     =# select sha512_crypt('clearpassword', 'somesalt');
						 sha512_crypt                                            
     ----------------------------------------------------------------------------------------------------
      $6$somesalt$dDcgWMHOtvHI6qT/Khi3uaaxXN6v4N9bnOeWFl/Y6K3pzxi/zKEhE1dAdjBybsMrfO2FU8JpFJMkQipkTaiFO0

## Functions

### `sha256_crypt(key text, salt text) RETURNS text`
Generate SHA256-CRYPT hash for `key` with `salt`.

### `sha512_crypt(key text, salt text) RETURNS text`
Generate SHA512-CRYPT hash for `key` with `salt`.

## Installation
The Makefile uses the [PGXS infrastructure](https://www.postgresql.org/docs/current/static/extend-pgxs.html) to find include and library files, and determine the install location.  
Build and install with:

	$ make
	$ (sudo) make install
