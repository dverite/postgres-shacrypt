#define SHA512_SALT_PREFIX "$6$"
#define SHA512_ROUNDS_PREFIX "rounds="

/* Structure to save state of computation between the single steps.  */
struct sha512_ctx
{
  uint64_t H[8];

  uint64_t total[2];
  uint64_t buflen;
  char buffer[256];	/* NB: always correctly aligned for uint64_t.  */
};

char *sha512_crypt_r (const char *key, const char *salt, char *buffer, int buflen);

char *sha512_crypt (const char *key, const char *salt);

