class Solution {
public:
	string intToRoman(int num){
		switch(num){
			case 0:
			return "";
			break;
			case 1:
			return "I";
			break;
			case 2:
			return "II";
			break;
			case 3:
			return "III";
			break;
			case 4:
			return "IV";
			break;
			case 5:
			return "V";
			break;
			case 6:
			return "VI";
			break;
			case 7:
			return "VII";
			break;
			case 8:
			return "VIII";
			break;
			case 9:
			return "IX";
			break;
			case 10:
			return "X";
			break;
			case 20:
			return "XX";
			break;
			case 30:
			return "XXX";
			break;
			case 40:
			return "XL";
			break;
			case 50:
			return "L";
			break;
			case 60:
			return "LX";
			break;
			case 70:
			return "LXX";
			break;
			case 80:
			return "LXXX";
			break;
			case 90:
			return "XC";
			break;
			case 100:
			return "C";
			break;
			case 200:
			return "CC";
			break;
			case 300:
			return "CCC";
			break;
			case 400:
			return "CD";
			break;
			case 500:
			return "D";
			break;
			case 600:
			return "DC";
			break;
			case 700:
			return "DCC";
			break;
			case 800:
			return "DCCC";
			break;
			case 900:
			return "CM";
			break;
			case 1000:
			return "M";
			break;
			case 2000:
			return "MM";
			break;
			case 3000:
			return "MMM";
			break;
			default:
				int thou = 0;
				int hund = 0;
				int deci = 0;
				int sing = 0;
				string result = "";
				sing = num % 10;
				num -= sing;
				if (num > 0)
				{
					deci = num % 100;
					num -= deci;
				if (num > 0)
				{
					hund = num % 1000;
					num -= hund;
				if (num > 0)
				{
					thou = num;
					result += intToRoman(thou);
				}
					result += intToRoman(hund);
				}
				result += intToRoman(deci);
			}
				result += intToRoman(sing);
				return result;
		}
	}
};