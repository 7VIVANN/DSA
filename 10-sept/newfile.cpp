if (incoming_value)
{
    if (stack_val)
    {
        push(exp_stack, c);
    }
    else
    {
        string pops = "";
        while ((!isnum(peek(exp_stack))) && (int(peek(exp_stack))) <= val)
        {
            pops += (char(pop(exp_stack)));
        }
        push(exp_stack, c);
        for (int k = pops.length() - 1; k >= 0; k--)
        {
            push(exp_stack, pops[k]);
        }
    }
}
else
{
    if (stack_val)
    {
        push(exp_stack, c);
    }
    else
    {
        char stack_operator = pop(exp_stack);
        push(exp_stack, int(stack_operator) < val ? stack_operator : val);
        push(exp_stack, int(stack_operator) > val ? stack_operator : val);
    }
}