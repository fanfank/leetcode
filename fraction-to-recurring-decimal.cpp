//A trick solution, because the use of 64-bit integer
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string sign = ((numerator < 0 && denominator < 0) ||
                (numerator > 0 && denominator > 0) ||
                numerator == 0) ? "" : "-";

        uint64_t u_numerator   = abs(numerator);
        uint64_t u_denominator = abs(denominator);
        if (numerator == 0x80000000) {
            u_numerator = 0x80000000;
        }
        if (denominator == 0x80000000) {
            u_denominator = 0x80000000;
        }

        std::ostringstream oss_buf;
        oss_buf<<(u_numerator / u_denominator);
        string left(oss_buf.str());

        uint64_t quotient = u_numerator % u_denominator;
        if (quotient == 0) {
            return sign + left;
        }

        map<uint64_t, std::size_t> used_numerators;
        map<uint64_t, std::size_t>::iterator p = used_numerators.end();
        string right = "";
        while (quotient != 0) {
            quotient *= 10;
            p = used_numerators.find(quotient);
            if (p != used_numerators.end()) {
                //recurring decimal
                right.insert(p->second, 1, '(');
                right.append(1, ')');
                break;
            }

            used_numerators[quotient] = right.size();
            right.append(1, quotient / u_denominator + '0');
            quotient = quotient % u_denominator;
        }
        
        return sign + left + "." + right;
    }
};
