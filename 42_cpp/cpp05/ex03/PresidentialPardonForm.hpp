/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:33:57 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/09 18:34:08 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		void execute(Bureaucrat const & executor) const;

	private:
		const std::string _target;
};

#endif
