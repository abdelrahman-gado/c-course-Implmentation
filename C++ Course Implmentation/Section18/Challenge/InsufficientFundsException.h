#ifndef INSUFFICIENTFUNDSEXCEPTION_H
#define INSUFFICIENTFUNDSEXCEPTION_H

class InsufficientFundsException : public std::exception
{
public:
    InsufficientFundsException() noexcept = default;
    ~InsufficientFundsException() = default;
    virtual const char *what() const noexcept override
    {
        return "Insuficient Funds Exception";
    }

};

#endif // INSUFFICIENTFUNDSEXCEPTION_H
