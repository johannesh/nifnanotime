#include <time.h>
#include "erl_nif.h"

static ERL_NIF_TERM
NIF_do_nothing(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
	return enif_make_long(env, 0);
}

static ERL_NIF_TERM
NIF_report_nanotime(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	long nanotime = ts.tv_sec * 1000000000l + ts.tv_nsec;
	return enif_make_long(env, nanotime);
}

static ErlNifFunc niftable[] = {
	{"do_nothing", 0, NIF_do_nothing},
	{"report_nanotime", 0, NIF_report_nanotime}
};

ERL_NIF_INIT(nifnanotime, niftable, NULL, NULL, NULL, NULL)
