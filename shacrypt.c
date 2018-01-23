/*
 * shacrypt.c
 *
 * PostgreSQL extension to generate SHA512-CRYPT and SHA256-CRYPT
 * password hashes.
 *
 * SHA-crypt code by Ulrich Drepper
 * See https://www.akkadia.org/drepper/SHA-crypt.txt
 * for the specification and code.
 *
 * PostgreSQL interface by Daniel Vérité, 2018. See LICENSE.md
 */

#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"

#include "sha256.h"
#include "sha512.h"


PG_MODULE_MAGIC;


PG_FUNCTION_INFO_V1(pg_sha256_crypt);
Datum pg_sha256_crypt(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(pg_sha512_crypt);
Datum pg_sha512_crypt(PG_FUNCTION_ARGS);


Datum pg_sha256_crypt(PG_FUNCTION_ARGS)
{
	char* str_input = text_to_cstring(PG_GETARG_TEXT_PP(0));
	char* str_salt = text_to_cstring(PG_GETARG_TEXT_PP(1));

	/* The allocation size is computed as in sha256_crypt() */
	int buf_size = (sizeof (SHA256_SALT_PREFIX) - 1
			+ sizeof (SHA256_ROUNDS_PREFIX) + 9 + 1
			+ strlen (str_salt) + 1 + 86 + 1);
	char *buffer = palloc(buf_size);
	char *result = sha256_crypt_r(str_input, str_salt, buffer, buf_size);

	PG_RETURN_TEXT_P(cstring_to_text(result));
}

Datum pg_sha512_crypt(PG_FUNCTION_ARGS)
{
	char* str_input = text_to_cstring(PG_GETARG_TEXT_PP(0));
	char* str_salt = text_to_cstring(PG_GETARG_TEXT_PP(1));

	/* The allocation size is computed as in sha512_crypt() */
	int buf_size = (sizeof (SHA512_SALT_PREFIX) - 1
			+ sizeof (SHA512_ROUNDS_PREFIX) + 9 + 1
			+ strlen (str_salt) + 1 + 86 + 1);
	char *buffer = palloc(buf_size);
	char *result = sha512_crypt_r(str_input, str_salt, buffer, buf_size);

	PG_RETURN_TEXT_P(cstring_to_text(result));
}
