#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    std::string l_input;
    std::getline(std::cin, l_input);
    
    const auto l_halfWayStep = l_input.size()/2;
    string l_overallDigitsSequence = l_input;
    l_overallDigitsSequence.insert(l_overallDigitsSequence.end(), l_input.begin(), l_input.begin() + l_halfWayStep);

    auto l_complementDigit = l_overallDigitsSequence.begin() + l_halfWayStep;
    auto captchaAccumulator = [&](long p_captcha, char p_digit){
                                auto l_validDigit = (isdigit(p_digit) && p_digit == *l_complementDigit)? (p_digit - '0') : 0;
                                l_complementDigit++;
                                return p_captcha + l_validDigit;
                              };
    auto captcha = std::accumulate(l_input.begin(), l_input.end(), 0, captchaAccumulator);
    cout << "Captcha evaluator = " << captcha << endl;
}