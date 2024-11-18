#ifndef RESULTS_H
#define RESULTS_H

double*** build_result_lines(time_complexity_t t_c, time_analysis_struct** t_a, int n);

int tc_to_index_start(time_complexity_t t_c);

void prepareResult(result_t *buf, int n);

char** build_headline(time_complexity_t t_c);

#endif