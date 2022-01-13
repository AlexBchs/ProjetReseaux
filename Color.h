#include <vector>

class Color
{

private:

	int r; // couleur rouge
	int g; // couleur verte
	int b; // couleur bleu

	int alpha; // valeur transparante du pixel pour meilleur visibilité
	// Les valeurs sont entre 0 et 255 (8 bits)

public:

	Color(int r, int g, int b, int a);
	Color(int r, int g, int b);
	Color(const Color& c, int a);
	Color(const Color& c);

	int R()const;
	int G()const;
	int B()const;
	int Alpha()const;

	void setR(int r);
	void setG(int g);
	void setB(int b);
	void setAlpha(int alpha);
};

