/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_LIS.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:35:05 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/08 16:59:18 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"



int* find_LIS(t_mystack *stack, int *length)
{
    int n = 0;
    t_mystack *temp = stack;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }

    int *seq = (int *)malloc(sizeof(int) * n);
    int *dp = (int *)malloc(sizeof(int) * n);
    int *previous = (int *)malloc(sizeof(int) * n); // To store previous indices for LIS reconstruction

    // Fill the sequence array and dp array
    temp = stack;
    int i = 0;
    while (temp != NULL)
    {
        seq[i] = temp->data;
        dp[i] = 1;  // each element is an increasing subsequence of length 1
        previous[i] = -1; // No previous element initially
        temp = temp->next;
        i++;
    }

    // Step 2: Compute the LIS using Dynamic Programming
    int max_LIS = 1;
    int last_index = 0; // To store the index of the last element of the LIS

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (seq[i] > seq[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                previous[i] = j;
            }
        }
        // Keep track of the maximum length and the corresponding index
        if (dp[i] > max_LIS)
        {
            max_LIS = dp[i];
            last_index = i;
        }
    }

    // Step 3: Reconstruct the LIS by tracing back using 'previous[]'
    int *LIS = (int *)malloc(sizeof(int) * max_LIS);
    int index = max_LIS - 1;
    while (last_index != -1)
    {
        LIS[index--] = seq[last_index];
        last_index = previous[last_index];
    }

    // Free other dynamically allocated memory
    free(seq);
    free(dp);
    free(previous);

    // Set the length of the LIS
    *length = max_LIS;

    return LIS;
}
