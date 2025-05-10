// tests/test_ghostComm.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../src/ghostComm.h"

static int passed = 0, failed = 0;

// compare strings; on failure print message and return 0 from the test fn
#define ASSERT_STREQ(expected, actual) do {                       \
    if (strcmp((expected), (actual)) != 0) {                      \
        fprintf(stderr,                                           \
            "    Assertion failed in %s (line %d):\n"             \
            "      expected: \"%s\"\n"                            \
            "      got:      \"%s\"\n",                          \
            __func__, __LINE__, (expected), (actual));           \
        return 0;                                                 \
    }                                                             \
} while (0)

// Each test returns 1 on success, 0 on failure:
int test_encode_empty() {
    char *out = encodeToMorse("");
    ASSERT_STREQ("", out);
    free(out);
    return 1;
}

int test_decode_empty() {
    char *out = decodeFromMorse("");
    ASSERT_STREQ("", out);
    free(out);
    return 1;
}

int test_encode_simple() {
    char *out = encodeToMorse("SOS");
    ASSERT_STREQ("... --- ... ", out);
    free(out);
    return 1;
}

int test_decode_simple() {
    char *out = decodeFromMorse("... --- ... ");
    ASSERT_STREQ("SOS", out);
    free(out);
    return 1;
}

int test_encode_with_space() {
    const char *expected = ".... . .-.. .-.. --- / .-- --- .-. .-.. -.. ";
    char *out = encodeToMorse("HELLO WORLD");
    ASSERT_STREQ(expected, out);
    free(out);
    return 1;
}

int test_decode_with_space() {
    const char *morse = ".... . .-.. .-.. --- / .-- --- .-. .-.. -.. ";
    char *out = decodeFromMorse((char*)morse);
    ASSERT_STREQ("HELLO WORLD", out);
    free(out);
    return 1;
}

int test_roundtrip_mixed() {
    const char *input = "Ghost123";
    char *enc = encodeToMorse((char*)input);
    char *dec = decodeFromMorse(enc);
    ASSERT_STREQ("GHOST123", dec);
    free(enc);
    free(dec);
    return 1;
}

int test_ignore_unknown_chars() {
    char *out = encodeToMorse("HELLO!");
    ASSERT_STREQ(".... . .-.. .-.. --- ", out);
    free(out);
    return 1;
}

int test_decode_unmapped_symbol() {
    char *out = decodeFromMorse(".-.- ");
    ASSERT_STREQ("", out);
    free(out);
    return 1;
}

// runner:
void run_test(int (*test)(), const char *name) {
    if (test()) {
        printf("[PASS] %s\n", name);
        passed++;
    } else {
        printf("[FAIL] %s\n", name);
        failed++;
    }
}

int main(void) {
    run_test(test_encode_empty,        "test_encode_empty");
    run_test(test_decode_empty,        "test_decode_empty");
    run_test(test_encode_simple,       "test_encode_simple");
    run_test(test_decode_simple,       "test_decode_simple");
    run_test(test_encode_with_space,   "test_encode_with_space");
    run_test(test_decode_with_space,   "test_decode_with_space");
    run_test(test_roundtrip_mixed,     "test_roundtrip_mixed");
    run_test(test_ignore_unknown_chars,"test_ignore_unknown_chars");
    run_test(test_decode_unmapped_symbol, "test_decode_unmapped_symbol");

    printf("\nSummary: %d/%d tests passed\n",
           passed, passed + failed);

    return (failed == 0) ? 0 : 1;
}
