/**
 * \file   cio.h
 * \author Oliver Stecklina <oliver.stecklina@th-luebeck.de>
 * \date   31.10.2023
 *
 * \brief  Console IO functions.
 */

#ifndef CIO_H_
#define CIO_H_

#define CIO_ECHO_ON  1
#define CIO_ECHO_OFF 0

/**
 * \brief Function reads from stdin until carriage return, newline, the given
 *        delimiter are detected or nine numbers were given. If all character
 *        are numbers a positive integer is returned otherwise the negative
 *        character code is returned.
 *
 * \param echo      turns console echo on or off
 * \param delimiter character which stops reading
 *
 * \return >= 0 if only numbers are read
 * \return <0   the negative character code
 */
int cio_get_number(const int echo, const char delimiter);

#endif /* CIO_H_ */
