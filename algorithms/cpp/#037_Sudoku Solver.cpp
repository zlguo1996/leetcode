class Solution {
public:
	vector<int> getValidNum(vector<short*>& vn, int r, int c, int b) {
		vector<int> vn_vector;
		short tmp = vn[0][r] | vn[1][c] | vn[2][b];

		int i = 1;
		while (i <= 9) {
			if ((tmp&(short)1) == 0) vn_vector.push_back(i);

			tmp = tmp >> 1;
			i++;
		}

		return vn_vector;
	}
	void tightenValidNum(vector<short*>& vn, int r, int c, int b, int num) {
		short n = 1 << (num - 1);

		vn[0][r] = vn[0][r] | n;
		vn[1][c] = vn[1][c] | n;
		vn[2][b] = vn[2][b] | n;
	}
	void relaxValidNum(vector<short*>& vn, int r, int c, int b, int num) {
		short n = 1 << (num - 1);

		vn[0][r] = vn[0][r] ^ n;
		vn[1][c] = vn[1][c] ^ n;
		vn[2][b] = vn[2][b] ^ n;
	}
	bool mySolveSudoku(vector<vector<char>>& board, vector<short*>& vn) {
		int i = 0;
		while (i != 9 * 9 && board[i / 9][i % 9] != '.') i++;

		if (i == 9 * 9) return true;
		else {
			int r = i / 9, c = i % 9;
			int br = r / 3, bc = c / 3;
			int b = br * 3 + bc;
			vector<int> vn_vector = getValidNum(vn, r, c, b);
			for (int i = 0; i<vn_vector.size(); i++) {
				board[r][c] = (char)('0' + vn_vector[i]);
				tightenValidNum(vn, r, c, b, vn_vector[i]);
				if (mySolveSudoku(board, vn)) return true;
				relaxValidNum(vn, r, c, b, vn_vector[i]);
				board[r][c] = '.';
			}
			return false;
		}
	}

	void solveSudoku(vector<vector<char>>& board) {
		// init valid number
		short vn_row[9], vn_col[9], vn_blk[9];
		for (int i = 0; i<9; i++) {
			vn_row[i] = 0;
			vn_col[i] = 0;
			vn_blk[i] = 0;
		}
		vector<short*> valid_num;
		valid_num.push_back(vn_row);
		valid_num.push_back(vn_col);
		valid_num.push_back(vn_blk);

		for (int i = 0; i<9 * 9; i++) {
			int r = i / 9, c = i % 9;
			int br = r / 3, bc = c / 3;
			int b = br * 3 + bc;

			char ch = board[r][c];
			if (ch != '.') tightenValidNum(valid_num, r, c, b, ch - '0');
		}

		mySolveSudoku(board, valid_num);
	}
};
