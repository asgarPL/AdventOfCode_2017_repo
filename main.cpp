//https://wandbox.org/permlink/hp2pCnER9SLY440g
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    std::string l_input;
    std::getline(std::cin, l_input);
    l_input.append(1, l_input[0]);

    struct Captcha
    {
        char m_previous;
        long m_captcha;
    };
    auto captchaAccumulator = [](Captcha p_captcha, char p_digit){
                                return Captcha({p_digit,
                                                (isdigit(p_digit) && p_captcha.m_previous == p_digit)?
                                                    p_captcha.m_captcha + (p_digit - '0') : p_captcha.m_captcha});
                              };
    auto captcha = std::accumulate(l_input.begin(), l_input.end(), Captcha({0, 0}), captchaAccumulator);
    cout << "Captcha evaluator = " << captcha.m_captcha << endl;
}