///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   tools.c                                            :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2023/06/20 14:47:43 by ckannane          #+#    #+#             */
///*   Updated: 2023/09/09 22:13:32 by ckannane         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */

//#include "../minishell.h"

//int is_whitespace(char c) {
//    return (c == ' ' || c == '\t' || c == '\n');
//}

//int count_words(char *str) {
//    int count = 0;
//    int i = 0;
//    int in_word = 0;
//    int in_quotes = 0;

//    while (str[i]) {
//        if (is_whitespace(str[i])) {
//            if (in_word && !in_quotes) {
//                count++;
//                in_word = 0;
//            }
//        } else {
//            if (!in_word) {
//                in_word = 1;
//            }
//        }

//        if (str[i] == '"' || str[i] == '\'') {
//            if (!in_quotes)
//                in_quotes = 1;
//            else
//                in_quotes = 0;
//        }

//        i++;
//    }

//    if (in_word && !in_quotes) {
//        count++;
//    }

//    return count;
//}

//char **split_arg(char *str) {
//    int word_count = count_words(str);

//    if(word_count == 0)
//     return NULL;
//    // Allocate memory for the array of strings
//    char **result = (char **)malloc((word_count + 1) * sizeof(char *));
//    if (result == NULL) {
//        return NULL;
//    }

//    int i = 0;
//    int j = 0;
//    int in_word = 0;
//    int word_length = 0;
//    int in_quotes = 0;

//    while (str[i]) {
//        if (is_whitespace(str[i])) {
//            if (in_word && !in_quotes) {
//                // Allocate memory for the word
//                result[j] = (char *)malloc((word_length + 1) * sizeof(char));
//                if (result[j] == NULL) {
//                    // Free memory in case of allocation failure
//                    for (int k = 0; k < j; k++)
//                        free(result[k]);
//                    free(result);
//                    return NULL;
//                }

//                // Copy the word into the array
//                strncpy(result[j], &str[i - word_length], word_length);
//                result[j][word_length] = '\0';

//                j++;
//                in_word = 0;
//                word_length = 0;
//            }
//        } else {
//            if (!in_word && !in_quotes) {
//                in_word = 1;
//            }
//            word_length++;
//        }

//        if (str[i] == '"' || str[i] == '\'') {
//            if (!in_quotes)
//                in_quotes = 1;
//            else
//                in_quotes = 0;
//        }

//        i++;
//    }

//    if (in_word && !in_quotes) {
//        // Allocate memory for the last word
//        result[j] = (char *)malloc((word_length + 1) * sizeof(char));
//        if (result[j] == NULL) {
//            // Free memory in case of allocation failure
//            for (int k = 0; k < j; k++)
//                free(result[k]);
//            free(result);
//            return NULL;
//        }

//        // Copy the last word into the array
//        strncpy(result[j], &str[i - word_length], word_length);
//        result[j][word_length] = '\0';

//        j++;
//    }

//    // Set the last element of the array to NULL
//    result[j] = NULL;

//    return result;
//}

//char* ft_strcpy(char* dest, const char* src) {
//    int srcLen = 0;
//    int destLen = 0;
//    char* destPtr;
//    char* destPos;
//    const char* srcPos;

//    while (src[srcLen] != '\0') {
//        srcLen++;
//    }

//    destPtr = (char*)malloc((srcLen + 1) * sizeof(char)); // Allocate memory for destination string

//    if (destPtr == NULL) {
//        // Memory allocation failed
//        return NULL;
//    }

//    destPos = destPtr;
//    srcPos = src;

//    while (*srcPos != '\0') {
//        *destPos = *srcPos;
//        destPos++;
//        srcPos++;
//    }

//    *destPos = '\0'; // Null-terminate the destination string

//    while (*destPtr != '\0') {
//        *dest = *destPtr;
//        dest++;
//        destPtr++;
//        destLen++;
//    }

//    *dest = '\0'; // Null-terminate the final destination string
//    free(destPtr); // Free the dynamically allocated memory for the destination string
//    return dest - destLen;
//}
