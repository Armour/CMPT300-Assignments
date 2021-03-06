/*------------------------------------------------------
 *
 *  line_io.c
 *
 *  this file contains contains two functions, one is input one
 *  line data from file and another is output one line data to file
 *
 *  Project         : LyreBird
 *  Name            : Chong Guo
 *  Student ID      : 301295753
 *  SFU username    : armourg
 *  Lecture section : D1
 *  Instructor      : Brain G.Booth
 *  TA              : Scott Kristjanson
 *
 *  Created by Armour on 15/09/2015
 *  Copyright (c) 2015 Armour. All rights reserved.
 *
 *------------------------------------------------------
 */

#include "line_io.h"
#include "memwatch.h"

/*
 * Function: input_line
 * -------------------
 *   Get each line tweet from file
 *
 *   Parameters:
 *      fin: pointer to input file
 *
 *   Returns:
 *      one line tweet content
 */

char *input_line(FILE *fin, int *len) {
    char c;
    char *line;
    int i = 0;

    line = (char *)malloc(sizeof(char) * (TWEETS_MAX_LENGTH));
    if (line == NULL) {                 /* If malloc error */
        return line;
    }

    c = fgetc(fin);
    while (c != EOF) {
        line[i++] = c;
        if (c == '\n') break;           /* Break when meet new line */
        c = fgetc(fin);
    }
    *len = i - 1;

    return line;
}

/*
 * Function: output_line
 * -------------------
 *   Output each line decryped tweet to file
 *
 *   Parameters:
 *      fout: pointer to output file
 *      tweet: decrypted tweet content
 *      len: length of decrypted tweet
 *
 *   Returns:
 *      void
 */

void output_line(FILE *fout, char *tweet, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        fprintf(fout, "%c", tweet[i]);
    }
    fprintf(fout, "\n");
}

