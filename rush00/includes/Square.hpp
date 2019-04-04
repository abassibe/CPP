/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Square.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:13:01 by pprikazs          #+#    #+#             */
/*   Updated: 2019/03/30 19:05:44 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_CLASS_H
# define SQUARE_CLASS_H

class Square
{
    public :
        Square(int, int, int, int);
        Square(Square const &);
        ~Square(void);

        int             getX(void) const;
        int             getY(void) const;
        int             getH(void) const;
        int             getW(void) const;

        void            setX(int);
        void            setY(int);
        void            setH(int);
        void            setW(int);
        void            setPos(int, int);
        void            setDim(int, int);

    private :
        int      _x;
        int      _y;
        int      _w;
        int      _h;

        Square(void);
};

#endif
