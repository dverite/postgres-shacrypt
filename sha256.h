/* Structure to save state of computation between the single steps.  */
struct sha256_ctx
{
  uint32_t H[8];

  uint32_t total[2];
  uint32_t buflen;
  char buffer[128];	/* NB: always correctly aligned for uint32_t.  */
};

/* Maximum salt string length.  */
#define SALT_LEN_MAX 16
/* Default number of rounds if not explicitly specified.  */
#define ROUNDS_DEFAULT 5000
/* Minimum number of rounds.  */
#define ROUNDS_MIN 1000
/* Maximum number of rounds.  */
#define ROUNDS_MAX 999999999

#define SHA256_SALT_PREFIX "$5$"
#define SHA256_ROUNDS_PREFIX "rounds="

char *sha256_crypt_r (const char *key, const char *salt, char *buffer, int buflen);

char *sha256_crypt (const char *key, const char *salt);

