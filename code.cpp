struct MyCounter
{
    unsigned counter;
    unsigned max;

    unsigned getCounter() const
    {
        return counter;
    }
    unsigned getMax() const
    {
        return max;
    }

    void increment()
    {
        counter++;
        if (counter > max)
            counter = 0;
    }

    void reset()
    {
        counter = 0;
    }

    void set(unsigned value)
    {
        counter = (value <= max) ? value : counter;
    }

    void setMax(unsigned value)
    {
        if (counter >= value)
            counter = 0;
        max = value;
        ;
    }
};