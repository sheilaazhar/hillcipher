/*
Sheila Azhar Almufarida (140810180001)
Sarah Navianti Dwi S. (140810180021)
Raissa Amini (140810180073)
Kelas A
Program Hill Cipher
*/

#include <iostream>
#include<string>

using namespace std;

//Fungsi Mod
int moduloFunc(int a, int b)
{
    int result = a % b;
    if (result < 0)
    {
        result += b;
    }
    return result;
}

//Fungsi Enkripsi
void Encryption()
{
    string msg;
    cout << "Masukan Plaintext yang akan di Enkripsi : ";
    getline(cin, msg);

    // Huruf Besar
    for (int i = 0; i < msg.length(); i++)
    {
        msg[i] = toupper(msg[i]);
    }

    // Jika msg.length %2 != 0 Melakukan Padding
    int lenChk = 0;
    if (msg.length() % 2 != 0)
    {
        msg += "0";
        lenChk = 1;
    }

    // message to 2x msg.length/2 matrix
    int msg2D[2][msg.length() / 2];
    int itr1 = 0;
    int itr2 = 0;
    for (int i = 0; i < msg.length(); i++)
    {
        if (i % 2 == 0)
        {
            msg2D[0][itr1] = msg[i] - 65;
            itr1++;
        }
        else
        {
            msg2D[1][itr2] = msg[i] - 65;
            itr2++;
        } //if-else
    }     // for

    // coba matrix alfabet
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < msg.length() / 2; j++)
        {
            cout << (msg2D[i][j]) << " ";
        }
        cout << endl;
    }

    cout << "Masukan key dalam bentuk matriks : " << endl;
    int key2D[2][2], transpose[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Masukkan matriks 2x2 : "; cin >> key2D[i][j];
        }
    }
    
    for (int i = 0; i < 2; i++){
    	for (int j = 0; j < 2; j++){
      		transpose[i][j] = key2D[i][j];
    	}
  	}
  	
    // tes kunci matrix
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << (transpose[i][j]) << " ";
        }
        cout <<endl;
    }

    // memeriksa validtas key
    // menemukan determinan
    int determin = key2D[0][0] * key2D[1][1] - key2D[0][1] * key2D[1][0];
    determin = moduloFunc(determin, 26);

    // multiplicative inverse
    int mulInv = -1;
    for (int i = 0; i < 26; i++)
    {
        int tempInv = determin * i;
        if (moduloFunc(tempInv, 26) == 1)
        {
            mulInv = i;
            break;
        }
        else
        {
            continue;
        }
    } // for


    string encrypText = "";
    int itrCount = msg.length() / 2;
    if (lenChk == 0)
    {
        // if msg.length % 2 == 0
        for (int i = 0; i < itrCount; i++)
        {
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            encrypText += (char)((temp1 % 26) + 65);
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            encrypText += (char)((temp2 % 26) + 65);
        }
    }
    else
    {
        // if msg.length % 2 == 0
        for (int i = 0; i < itrCount - 1; i++)
        {
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            encrypText += (char)((temp1 % 26) + 65);
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            encrypText += (char)((temp2 % 26) + 65);
        }
    }

    cout << endl
         << "Hasil Enkripsi : " << encrypText << endl;
}

//Fungsi Dekripsi
void Decryption()
{
    string msg;
    cout << "Masukan Ciphertext yang akan di Deskrip : ";
    getline(cin, msg);

    // Huruf besar
    for (int i = 0; i < msg.length(); i++)
    {
        msg[i] = toupper(msg[i]);
    }

    // if msg.length %2 != 0 melakukan padding
    int lenChk = 0;
    if (msg.length() % 2 != 0)
    {
        msg += "0";
        lenChk = 1;
    }

    // message to 2x msg.length/2 matrix
    int msg2D[2][msg.length() / 2];
    int itr1 = 0;
    int itr2 = 0;
    for (int i = 0; i < msg.length(); i++)
    {
        if (i % 2 == 0)
        {
            msg2D[0][itr1] = msg[i] - 65;
            itr1++;
        }
        else
        {
            msg2D[1][itr2] = msg[i] - 65;
            itr2++;
        } //if-else
    }     // for

    // tes matriks alfabet
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < msg.length() / 2; j++)
        {
            cout << (msg2D[i][j]) << " ";
        }
        cout << endl;
    }

    cout << "Masukan key dalam bentuk matriks : " << endl;
    int key2D[2][2], transpose[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Masukkan matriks 2x2 : "; cin >> key2D[i][j];
        }
    }
    
    for (int i = 0; i < 2; i++){
    	for (int j = 0; j < 2; j++){
      		transpose[i][j] = key2D[i][j];
    	}
  	}
  	
    // coba matrix key
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << (transpose[i][j]) << " ";
        }
        cout <<endl;
    }

    // determinant
    int deter = key2D[0][0] * key2D[1][1] - key2D[0][1] * key2D[1][0];
    deter = moduloFunc(deter, 26);

    //  multiplicative inverse
    int mulInv = -1;
    for (int i = 0; i < 26; i++)
    {
        int tempInv = deter * i;
        if (moduloFunc(tempInv, 26) == 1)
        {
            mulInv = i;
            break;
        }
        else
        {
            continue;
        }
    } // for

    // adjugate matrix
    //swapping
    swap(key2D[0][0], key2D[1][1]);

    // changing signs
    key2D[0][1] *= -1;
    key2D[1][0] *= -1;

    key2D[0][1] = moduloFunc(key2D[0][1], 26);
    key2D[1][0] = moduloFunc(key2D[1][0], 26);

    //mengalikan pembalikan perkalian dengan matriks adjugat
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            key2D[i][j] *= mulInv;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            key2D[i][j] = moduloFunc(key2D[i][j], 26);
        }
    }

    // ciphertext ke plain text
    string decrypText = "";
    int itrCount = msg.length() / 2;
    if (lenChk == 0)
    {
        // if msg.length % 2 == 0
        for (int i = 0; i < itrCount; i++)
        {
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            decrypText += (char)((temp1 % 26) + 65);
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            decrypText += (char)((temp2 % 26) + 65);
        }
    }
    else
    {
        // if msg.length % 2 == 0
        for (int i = 0; i < itrCount - 1; i++)
        {
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            decrypText += (char)((temp1 % 26) + 65);
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            decrypText += (char)((temp2 % 26) + 65);
        }
    }

    cout << endl << "Hasil Dekripsi : " << decrypText << endl;
}



int main()
{
    int pil;
    bool stop;
    stop = false;
    char more = 'Y';

    while (more == 'Y')
    {
    	system("cls");
       	cout << "==============================" << endl;
		cout << "    PROGRAM HILL CIPHER 2x2   " << endl;
		cout << "==============================" << endl;
		cout << " 1. Enkripsi                  " << endl;
		cout << " 2. Dekripsi                  " << endl;
		cout << " 3. Keluar					   " << endl;
		cout << "==============================" << endl;
        cout << "Pilih menu : ";
        cin >> pil;
        cin.ignore();
        system("cls");
        switch (pil)
        {
        case 1:
            cout << endl << "Enkripsi" << endl;
            Encryption();
            break;
        case 2:
            cout << endl << "Dekripsi" << endl;
            Decryption();
            break;
        case 3:
            stop = true;
            break;
        default :
        	cout << "\npilihan Anda salah, Silahkan pilih yang sudah ada pada Menu!!"<< endl;
        }
        cout <<"\n\nTekan 'Y' jika ingin melanjutkan program ini" <<endl;
        cin >> more;
    }
    return 0;
}
