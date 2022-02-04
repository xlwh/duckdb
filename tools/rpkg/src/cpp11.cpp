// Generated by cpp11: do not edit by hand
// clang-format off

#include "duckdb_types.hpp"
#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// rapi.cpp
cpp11::external_pointer<duckdb::DBWrapper> startup_R(cpp11::strings dbdirsexp, cpp11::logicals readonlysexp, cpp11::list configsexp);
extern "C" SEXP _duckdb_startup_R(SEXP dbdirsexp, SEXP readonlysexp, SEXP configsexp) {
  BEGIN_CPP11
    return cpp11::as_sexp(startup_R(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(dbdirsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(readonlysexp), cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(configsexp)));
  END_CPP11
}
// rapi.cpp
void shutdown_R(cpp11::external_pointer<duckdb::DBWrapper> dbsexp);
extern "C" SEXP _duckdb_shutdown_R(SEXP dbsexp) {
  BEGIN_CPP11
    shutdown_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::DBWrapper>>>(dbsexp));
    return R_NilValue;
  END_CPP11
}
// rapi.cpp
cpp11::external_pointer<duckdb::ConnWrapper> connect_R(cpp11::external_pointer<duckdb::DBWrapper> dbsexp);
extern "C" SEXP _duckdb_connect_R(SEXP dbsexp) {
  BEGIN_CPP11
    return cpp11::as_sexp(connect_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::DBWrapper>>>(dbsexp)));
  END_CPP11
}
// rapi.cpp
void disconnect_R(cpp11::external_pointer<duckdb::ConnWrapper> connsexp);
extern "C" SEXP _duckdb_disconnect_R(SEXP connsexp) {
  BEGIN_CPP11
    disconnect_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::ConnWrapper>>>(connsexp));
    return R_NilValue;
  END_CPP11
}
// rapi.cpp
cpp11::list prepare_R(cpp11::external_pointer<duckdb::ConnWrapper> connsexp, cpp11::strings querysexp);
extern "C" SEXP _duckdb_prepare_R(SEXP connsexp, SEXP querysexp) {
  BEGIN_CPP11
    return cpp11::as_sexp(prepare_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::ConnWrapper>>>(connsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(querysexp)));
  END_CPP11
}
// rapi.cpp
cpp11::list bind_R(cpp11::external_pointer<duckdb::RStatement> stmtsexp, cpp11::list paramsexp, cpp11::logicals arrowsexp);
extern "C" SEXP _duckdb_bind_R(SEXP stmtsexp, SEXP paramsexp, SEXP arrowsexp) {
  BEGIN_CPP11
    return cpp11::as_sexp(bind_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::RStatement>>>(stmtsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(paramsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(arrowsexp)));
  END_CPP11
}
// rapi.cpp
SEXP execute_R(cpp11::external_pointer<duckdb::RStatement> stmtsexp, cpp11::logicals arrowsexp);
extern "C" SEXP _duckdb_execute_R(SEXP stmtsexp, SEXP arrowsexp) {
  BEGIN_CPP11
    return cpp11::as_sexp(execute_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::RStatement>>>(stmtsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(arrowsexp)));
  END_CPP11
}
// rapi.cpp
SEXP fetch_arrow_R(SEXP query_resultsexp, cpp11::logicals streamsexp, cpp11::doubles vector_per_chunksexp, cpp11::logicals return_tablesexp);
extern "C" SEXP _duckdb_fetch_arrow_R(SEXP query_resultsexp, SEXP streamsexp, SEXP vector_per_chunksexp, SEXP return_tablesexp) {
  BEGIN_CPP11
    return cpp11::as_sexp(fetch_arrow_R(cpp11::as_cpp<cpp11::decay_t<SEXP>>(query_resultsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(streamsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::doubles>>(vector_per_chunksexp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(return_tablesexp)));
  END_CPP11
}
// rapi.cpp
SEXP fetch_record_batch_R(SEXP query_resultsexp, cpp11::doubles approx_batch_sizeexp);
extern "C" SEXP _duckdb_fetch_record_batch_R(SEXP query_resultsexp, SEXP approx_batch_sizeexp) {
  BEGIN_CPP11
    return cpp11::as_sexp(fetch_record_batch_R(cpp11::as_cpp<cpp11::decay_t<SEXP>>(query_resultsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::doubles>>(approx_batch_sizeexp)));
  END_CPP11
}
// rapi.cpp
SEXP release_R(cpp11::external_pointer<duckdb::RStatement> stmtsexp);
extern "C" SEXP _duckdb_release_R(SEXP stmtsexp) {
  BEGIN_CPP11
    return cpp11::as_sexp(release_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::RStatement>>>(stmtsexp)));
  END_CPP11
}
// rapi.cpp
void register_R(cpp11::external_pointer<duckdb::ConnWrapper> connsexp, cpp11::strings namesexp, cpp11::list valuesexp);
extern "C" SEXP _duckdb_register_R(SEXP connsexp, SEXP namesexp, SEXP valuesexp) {
  BEGIN_CPP11
    register_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::ConnWrapper>>>(connsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(namesexp), cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(valuesexp));
    return R_NilValue;
  END_CPP11
}
// rapi.cpp
void unregister_R(cpp11::external_pointer<duckdb::ConnWrapper> connsexp, cpp11::strings namesexp);
extern "C" SEXP _duckdb_unregister_R(SEXP connsexp, SEXP namesexp) {
  BEGIN_CPP11
    unregister_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::ConnWrapper>>>(connsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(namesexp));
    return R_NilValue;
  END_CPP11
}
// rapi.cpp
void register_arrow_R(cpp11::external_pointer<duckdb::ConnWrapper> connsexp, cpp11::strings namesexp, cpp11::list export_funsexp, SEXP valuesexp);
extern "C" SEXP _duckdb_register_arrow_R(SEXP connsexp, SEXP namesexp, SEXP export_funsexp, SEXP valuesexp) {
  BEGIN_CPP11
    register_arrow_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::ConnWrapper>>>(connsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(namesexp), cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(export_funsexp), cpp11::as_cpp<cpp11::decay_t<SEXP>>(valuesexp));
    return R_NilValue;
  END_CPP11
}
// rapi.cpp
void unregister_arrow_R(cpp11::external_pointer<duckdb::ConnWrapper> connsexp, cpp11::strings namesexp);
extern "C" SEXP _duckdb_unregister_arrow_R(SEXP connsexp, SEXP namesexp) {
  BEGIN_CPP11
    unregister_arrow_R(cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<duckdb::ConnWrapper>>>(connsexp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(namesexp));
    return R_NilValue;
  END_CPP11
}
// rapi.cpp
cpp11::strings ptr_to_str(SEXP extptr);
extern "C" SEXP _duckdb_ptr_to_str(SEXP extptr) {
  BEGIN_CPP11
    return cpp11::as_sexp(ptr_to_str(cpp11::as_cpp<cpp11::decay_t<SEXP>>(extptr)));
  END_CPP11
}
// relational.cpp
SEXP expr_reference_cpp(std::string ref);
extern "C" SEXP _duckdb_expr_reference_cpp(SEXP ref) {
  BEGIN_CPP11
    return cpp11::as_sexp(expr_reference_cpp(cpp11::as_cpp<cpp11::decay_t<std::string>>(ref)));
  END_CPP11
}
// relational.cpp
SEXP expr_constant_cpp(sexp val);
extern "C" SEXP _duckdb_expr_constant_cpp(SEXP val) {
  BEGIN_CPP11
    return cpp11::as_sexp(expr_constant_cpp(cpp11::as_cpp<cpp11::decay_t<sexp>>(val)));
  END_CPP11
}
// relational.cpp
SEXP expr_function_cpp(std::string name, list args);
extern "C" SEXP _duckdb_expr_function_cpp(SEXP name, SEXP args) {
  BEGIN_CPP11
    return cpp11::as_sexp(expr_function_cpp(cpp11::as_cpp<cpp11::decay_t<std::string>>(name), cpp11::as_cpp<cpp11::decay_t<list>>(args)));
  END_CPP11
}
// relational.cpp
std::string expr_tostring_cpp(duckdb::expr_extptr expr);
extern "C" SEXP _duckdb_expr_tostring_cpp(SEXP expr) {
  BEGIN_CPP11
    return cpp11::as_sexp(expr_tostring_cpp(cpp11::as_cpp<cpp11::decay_t<duckdb::expr_extptr>>(expr)));
  END_CPP11
}
// relational.cpp
SEXP rel_from_df_cpp(duckdb::con_extptr con, data_frame df);
extern "C" SEXP _duckdb_rel_from_df_cpp(SEXP con, SEXP df) {
  BEGIN_CPP11
    return cpp11::as_sexp(rel_from_df_cpp(cpp11::as_cpp<cpp11::decay_t<duckdb::con_extptr>>(con), cpp11::as_cpp<cpp11::decay_t<data_frame>>(df)));
  END_CPP11
}
// relational.cpp
SEXP rel_filter_cpp(duckdb::rel_extptr rel, duckdb::expr_extptr expr);
extern "C" SEXP _duckdb_rel_filter_cpp(SEXP rel, SEXP expr) {
  BEGIN_CPP11
    return cpp11::as_sexp(rel_filter_cpp(cpp11::as_cpp<cpp11::decay_t<duckdb::rel_extptr>>(rel), cpp11::as_cpp<cpp11::decay_t<duckdb::expr_extptr>>(expr)));
  END_CPP11
}
// relational.cpp
SEXP rel_project_cpp(duckdb::rel_extptr rel, list exprs_p);
extern "C" SEXP _duckdb_rel_project_cpp(SEXP rel, SEXP exprs_p) {
  BEGIN_CPP11
    return cpp11::as_sexp(rel_project_cpp(cpp11::as_cpp<cpp11::decay_t<duckdb::rel_extptr>>(rel), cpp11::as_cpp<cpp11::decay_t<list>>(exprs_p)));
  END_CPP11
}
// relational.cpp
SEXP rel_aggregate_cpp(duckdb::rel_extptr rel, list groups_p, list aggregates_p);
extern "C" SEXP _duckdb_rel_aggregate_cpp(SEXP rel, SEXP groups_p, SEXP aggregates_p) {
  BEGIN_CPP11
    return cpp11::as_sexp(rel_aggregate_cpp(cpp11::as_cpp<cpp11::decay_t<duckdb::rel_extptr>>(rel), cpp11::as_cpp<cpp11::decay_t<list>>(groups_p), cpp11::as_cpp<cpp11::decay_t<list>>(aggregates_p)));
  END_CPP11
}
// relational.cpp
SEXP rel_order_cpp(duckdb::rel_extptr rel, list orders_p);
extern "C" SEXP _duckdb_rel_order_cpp(SEXP rel, SEXP orders_p) {
  BEGIN_CPP11
    return cpp11::as_sexp(rel_order_cpp(cpp11::as_cpp<cpp11::decay_t<duckdb::rel_extptr>>(rel), cpp11::as_cpp<cpp11::decay_t<list>>(orders_p)));
  END_CPP11
}
// relational.cpp
SEXP rel_to_df_cpp(duckdb::rel_extptr rel);
extern "C" SEXP _duckdb_rel_to_df_cpp(SEXP rel) {
  BEGIN_CPP11
    return cpp11::as_sexp(rel_to_df_cpp(cpp11::as_cpp<cpp11::decay_t<duckdb::rel_extptr>>(rel)));
  END_CPP11
}
// relational.cpp
std::string rel_tostring_cpp(duckdb::rel_extptr rel);
extern "C" SEXP _duckdb_rel_tostring_cpp(SEXP rel) {
  BEGIN_CPP11
    return cpp11::as_sexp(rel_tostring_cpp(cpp11::as_cpp<cpp11::decay_t<duckdb::rel_extptr>>(rel)));
  END_CPP11
}
// relational.cpp
SEXP rel_explain_cpp(duckdb::rel_extptr rel);
extern "C" SEXP _duckdb_rel_explain_cpp(SEXP rel) {
  BEGIN_CPP11
    return cpp11::as_sexp(rel_explain_cpp(cpp11::as_cpp<cpp11::decay_t<duckdb::rel_extptr>>(rel)));
  END_CPP11
}
// relational.cpp
SEXP rel_sql_cpp(duckdb::rel_extptr rel, std::string sql);
extern "C" SEXP _duckdb_rel_sql_cpp(SEXP rel, SEXP sql) {
  BEGIN_CPP11
    return cpp11::as_sexp(rel_sql_cpp(cpp11::as_cpp<cpp11::decay_t<duckdb::rel_extptr>>(rel), cpp11::as_cpp<cpp11::decay_t<std::string>>(sql)));
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_duckdb_bind_R",               (DL_FUNC) &_duckdb_bind_R,               3},
    {"_duckdb_connect_R",            (DL_FUNC) &_duckdb_connect_R,            1},
    {"_duckdb_disconnect_R",         (DL_FUNC) &_duckdb_disconnect_R,         1},
    {"_duckdb_execute_R",            (DL_FUNC) &_duckdb_execute_R,            2},
    {"_duckdb_expr_constant_cpp",    (DL_FUNC) &_duckdb_expr_constant_cpp,    1},
    {"_duckdb_expr_function_cpp",    (DL_FUNC) &_duckdb_expr_function_cpp,    2},
    {"_duckdb_expr_reference_cpp",   (DL_FUNC) &_duckdb_expr_reference_cpp,   1},
    {"_duckdb_expr_tostring_cpp",    (DL_FUNC) &_duckdb_expr_tostring_cpp,    1},
    {"_duckdb_fetch_arrow_R",        (DL_FUNC) &_duckdb_fetch_arrow_R,        4},
    {"_duckdb_fetch_record_batch_R", (DL_FUNC) &_duckdb_fetch_record_batch_R, 2},
    {"_duckdb_prepare_R",            (DL_FUNC) &_duckdb_prepare_R,            2},
    {"_duckdb_ptr_to_str",           (DL_FUNC) &_duckdb_ptr_to_str,           1},
    {"_duckdb_register_R",           (DL_FUNC) &_duckdb_register_R,           3},
    {"_duckdb_register_arrow_R",     (DL_FUNC) &_duckdb_register_arrow_R,     4},
    {"_duckdb_rel_aggregate_cpp",    (DL_FUNC) &_duckdb_rel_aggregate_cpp,    3},
    {"_duckdb_rel_explain_cpp",      (DL_FUNC) &_duckdb_rel_explain_cpp,      1},
    {"_duckdb_rel_filter_cpp",       (DL_FUNC) &_duckdb_rel_filter_cpp,       2},
    {"_duckdb_rel_from_df_cpp",      (DL_FUNC) &_duckdb_rel_from_df_cpp,      2},
    {"_duckdb_rel_order_cpp",        (DL_FUNC) &_duckdb_rel_order_cpp,        2},
    {"_duckdb_rel_project_cpp",      (DL_FUNC) &_duckdb_rel_project_cpp,      2},
    {"_duckdb_rel_sql_cpp",          (DL_FUNC) &_duckdb_rel_sql_cpp,          2},
    {"_duckdb_rel_to_df_cpp",        (DL_FUNC) &_duckdb_rel_to_df_cpp,        1},
    {"_duckdb_rel_tostring_cpp",     (DL_FUNC) &_duckdb_rel_tostring_cpp,     1},
    {"_duckdb_release_R",            (DL_FUNC) &_duckdb_release_R,            1},
    {"_duckdb_shutdown_R",           (DL_FUNC) &_duckdb_shutdown_R,           1},
    {"_duckdb_startup_R",            (DL_FUNC) &_duckdb_startup_R,            3},
    {"_duckdb_unregister_R",         (DL_FUNC) &_duckdb_unregister_R,         2},
    {"_duckdb_unregister_arrow_R",   (DL_FUNC) &_duckdb_unregister_arrow_R,   2},
    {NULL, NULL, 0}
};
}

void AltrepString_Initialize(DllInfo* dll);

extern "C" attribute_visible void R_init_duckdb(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  AltrepString_Initialize(dll);
  R_forceSymbols(dll, TRUE);
}
