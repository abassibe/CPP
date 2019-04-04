/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rand.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:23:51 by pprikazs          #+#    #+#             */
/*   Updated: 2019/03/30 17:24:55 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAND_CLASS_H
# define RAND_CLASS_H

class Rand
{
    public:
        Rand(Rand const &);
        ~Rand(void);

        static bool          getOneTo(int _fr);
        static int           getOneOf(int _base, int to);
    private:
        Rand(void);
};

#endif
