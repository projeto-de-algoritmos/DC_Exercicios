// https://leetcode.com/problems/longest-nice-substring/description/

let longestNiceSubstring = (string) => {
    const strLen = string.length;
    if (strLen < 2) return "";
    const lettersSet = new Set(string.split(""));
    for (let i = 0; i < strLen; i++) {
      if (
        !lettersSet.has(string[i].toUpperCase()) ||
        !lettersSet.has(string[i].toLowerCase())
      ) {
        const str1 = longestNiceSubstring(string.substr(0, i));
        const str2 = longestNiceSubstring(string.substr(i + 1, strLen));
  
        return str1.length >= str2.length ? str1 : str2;
      }
    }
    return string;
  };