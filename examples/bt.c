#include <stdio.h>
#include "backtrace.h"
#include "backtrace-supported.h"

struct bt_ctx {
	struct backtrace_state *state;
	int error;
};

static void error_callback(void *data, const char *msg, int errnum)
{
	struct bt_ctx *ctx = data;
	fprintf(stderr, "ERROR: %s (%d)", msg, errnum);
	ctx->error = 1;
}

static void syminfo_callback (void *data, uintptr_t pc, const char *symname, uintptr_t symval, uintptr_t symsize)
{
	//struct bt_ctx *ctx = data;
	if (symname) {
		printf("%lx %s ??:0\n", (unsigned long)pc, symname);
	} else {
		printf("%lx ?? ??:0\n", (unsigned long)pc);
	}
}

static int full_callback(void *data, uintptr_t pc, const char *filename, int lineno, const char *function)
{
	struct bt_ctx *ctx = data;
	if (function) {
		printf("%lx %s %s:%d\n", (unsigned long)pc, function, filename?filename:"??", lineno);
	} else {
		backtrace_syminfo (ctx->state, pc, syminfo_callback, error_callback, data);
	}
	return 0;
}

static int simple_callback(void *data, uintptr_t pc)
{
	struct bt_ctx *ctx = data;
	backtrace_pcinfo(ctx->state, pc, full_callback, error_callback, data);
	return 0;
}

static inline void bt(struct backtrace_state *state)
{
	struct bt_ctx ctx = {state, 0};
	backtrace_print(state, 0, stdout);
	backtrace_simple(state, 0, simple_callback, error_callback, &ctx);
}

int main(int argc, char *argv[])
{
	struct backtrace_state *state = backtrace_create_state (argv[0], BACKTRACE_SUPPORTS_THREADS, error_callback, NULL);
	bt(state);
	return 0;
}
