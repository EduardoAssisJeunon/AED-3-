#include <iostream>

using namespace std;

class celula
{
private:
	string nome;
	int idade;
	string beber;
	string sexo;
	celula * proxima;
public:
	celula()
	{
		proxima = NULL;
	}
	celula(string n, string s, int i, string d)
	{
		nome = n;
		sexo = s;
		idade = i;
		beber = d;

	}
	celula(string n, string s, int i, string d,  celula *p){
		nome = n;
        sexo = s;
		idade = i;
		beber = d;

		proxima = p;
	}
	string getNome()
	{
		return nome;
	}
	void setNome(string n)
	{
		nome = n;
	}
		string getSexo()
	{
		return sexo;
	}
	void setSexo(string s)
	{
		sexo = s;
	}
	int getIdade()
	{
		return idade;
	}
	void setIdade(int i)
	{
		idade = i;
	}
	string getBeber()
	{
		return beber;
	}
	void setBeber(string d)
	{
		beber = d;
	}

	celula * getProxima()
	{
		return proxima;
	}
	void setProxima(celula * l)
	{
		proxima = l;
	}
};

class lista
{
private:
	celula * inicio;

public:
	lista()
	{
		inicio = NULL;
	}
	lista(celula *b)
	{
		inicio = b;
	}
	~lista()
	{
		esvaziar();
		cout << "\nPassou no metodo destrutor";
	}
	celula * getInicio()
	{
		return inicio;
	}

	void setInicio(celula *b)
	{
		inicio = b;
	}

	void inserirInicio(string n , string s, int i, string d)
	{
		celula *nova = new celula;
		nova->setNome(n);
		nova->setSexo(s);
		nova->setIdade(i);
		nova->setBeber(d);

		nova->setProxima(inicio);
		inicio = nova;
	}

	void inserirFim(string n, string s, int i, string d)
	{
		celula *nova = new celula(n, s, i, d, NULL);
		//nova->setNome(n);
		//nova->setProxima(NULL);
		if(inicio == NULL)
		{
			inicio = nova;
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			aux->setProxima(nova);
		}
	}


	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
			while(aux != NULL)
			{
				cout << aux->getNome() << " // ";
				cout << aux->getSexo() << " // ";
				cout << aux->getIdade() << " // ";
				cout << aux->getBeber() << endl;
				aux = aux->getProxima();
			}
		}
	}

	void esvaziar()
	{
		celula *aux = inicio;
		while(aux != NULL)
		{
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\nLista esvaziada com sucesso.";
	}
};

int main()
{
	lista listaAlunos;
	listaAlunos.inserirInicio("Duardo", "Masculino", 19, "Derrama");
	listaAlunos.inserirInicio("DJ", "Feminino", 20, "Nao bebe");
	listaAlunos.inserirFim("Ratin", "Indefinido", 19, "Bebe pra carai");
	listaAlunos.imprimir();
	return 0;
}
