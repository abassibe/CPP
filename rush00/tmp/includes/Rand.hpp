/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rand.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:23:51 by pprikazs          #+#    #+#             */
/*   Updated: 2019/03/31 21:20:24 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAND_CLASS_H
# define RAND_CLASS_H

#include "Square.hpp"
#include "time.h"
#include "Win.hpp"

class Rand
{
    public:
        Rand(Rand const &);
        ~Rand(void);

        static bool          getOneTo(int _fr);
        static int           getOneOf(int _base, int to);

        static void          generateEnnemy(clock_t &t,Win &);

    private:
        Rand(void);
};

#endif
