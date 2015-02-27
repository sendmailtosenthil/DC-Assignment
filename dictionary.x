struct WM{
	string word<>;
	string meaning<>;
};

program DICTIONARY{
	version DICTIONARY_VER{
		string newWord(WM m)=1;
		string searchWord(string word) = 2;
		string deleteWord(string word) = 3;
	} = 1;
} = 0x3a3afeeb;