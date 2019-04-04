/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:01:20 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 18:51:20 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock
{
	public:
		OfficeBlock();
		OfficeBlock(Intern *intern, Bureaucrat *signatory, Bureaucrat *executor);
		~OfficeBlock();
		void	setIntern(Intern *intern);
		void	setSignatory(Bureaucrat *signatory);
		void	setExecutor(Bureaucrat *executor);
		void	doBureaucracy(std::string form, std::string target);

		class	MissingInternException : public std::exception
		{
			public:
				MissingInternException() throw();
				MissingInternException(MissingInternException const& copy) throw();
				~MissingInternException() throw();
				MissingInternException	&operator=(MissingInternException const& copy) throw();
				const char				*what() const throw();
		};

		class	MissingSignatoryException : public std::exception
		{
			public:
				MissingSignatoryException() throw();
				MissingSignatoryException(MissingSignatoryException const& copy) throw();
				~MissingSignatoryException() throw();
				MissingSignatoryException	&operator=(MissingSignatoryException const& copy) throw();
				const char				*what() const throw();
		};

		class	MissingExecutorException : public std::exception
		{
			public:
				MissingExecutorException() throw();
				MissingExecutorException(MissingExecutorException const& copy) throw();
				~MissingExecutorException() throw();
				MissingExecutorException	&operator=(MissingExecutorException const& copy) throw();
				const char				*what() const throw();
		};

	private:
		OfficeBlock(OfficeBlock const& copy);
		OfficeBlock		&operator=(OfficeBlock const& copy);
		Intern			*_intern;
		Bureaucrat		*_signatory;
		Bureaucrat		*_executor;
};

#endif
