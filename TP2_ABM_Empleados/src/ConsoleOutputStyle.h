#ifndef CONSOLEOUTPUTSTYLE_H_INCLUDED
#define CONSOLEOUTPUTSTYLE_H_INCLUDED

enum Colors { // Listado de colores (La letra "L" al inicio, indica que es un color más claro que su antecesor).
 BLACK = 0,
 BLUE = 1,
 GREEN = 2,
 CYAN = 3,
 RED = 4,
 MAGENTA = 5,
 BROWN = 6,
 LGRAY = 7,
 DGRAY = 8,
 LBLUE = 9,
 LGREEN = 10,
 LCYAN = 11,
 LRED = 12,
 LMAGENTA = 13,
 YELLOW = 14,
 WHITE = 15
};

/** \brief Changes the text colour and background
 *
 * \param background It is the background colour value
 * \param text It is the text colour value
 * \return The font colour and background change
 *
 */
void Colour(int background, int text);

#endif // CONSOLEOUTPUTSTYLE_H_INCLUDED
