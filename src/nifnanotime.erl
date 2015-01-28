-module (nifnanotime).
-on_load (init/0).
-export ([
	do_nothing/0,
	report_nanotime/0,
	measure_nifinvoke_cost/0
	]).

init() ->
	Nif = filename:join("priv", "nifnanotime"),
	erlang:load_nif(Nif, 0).

do_nothing() ->
	erlang:nif_error(not_loaded).

report_nanotime() ->
	erlang:nif_error(not_loaded).

measure_nifinvoke_cost() ->
	N = 10000000, % 10e6
	Before = report_nanotime(),

	invoke_nifs(N),

	After = report_nanotime(),
	Duration = After - Before,

	Duration / N.

invoke_nifs(0) -> done;
invoke_nifs(N) ->
	do_nothing(),
	invoke_nifs(N-1).
