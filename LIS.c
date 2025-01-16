void find_lis(t_parsed_data *my_data, t_mystack **a_b[2],
              int *lis, int *lis_len)
{
    t_mystack *curr;
    t_mystack *a;
    int i, j;
    
    a = *a_b[0];
    curr = a->next;
    *lis_len = 1;
    lis[0] = a->data;

    while (curr)
    {
        // Try to add current node's data to the LIS if it's greater than
        // the last element of the LIS found so far.
        if (curr->data > lis[*lis_len - 1])
        {
            lis[*lis_len] = curr->data;
            (*lis_len)++;
        }
        else
        {
            // Find the first element in LIS that is greater than current data
            // to replace it, in order to maintain the increasing subsequence.
            for (i = 0; i < *lis_len; i++)
            {
                if (lis[i] > curr->data)
                {
                    lis[i] = curr->data;
                    break;
                }
            }
        }
        curr = curr->next;
    }
}




// accurate but wrong