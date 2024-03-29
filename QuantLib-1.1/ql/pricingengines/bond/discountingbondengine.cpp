/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2007 Giorgio Facchinetti
 Copyright (C) 2009 StatPro Italia srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#include <ql/pricingengines/bond/discountingbondengine.hpp>
#include <ql/cashflows/cashflows.hpp>

namespace QuantLib {

    DiscountingBondEngine::DiscountingBondEngine(
                             const Handle<YieldTermStructure>& discountCurve,
                             boost::optional<bool> includeSettlementDateFlows)
    : discountCurve_(discountCurve),
      includeSettlementDateFlows_(includeSettlementDateFlows) {
        registerWith(discountCurve_);
    }

    void DiscountingBondEngine::calculate() const {
        QL_REQUIRE(!discountCurve_.empty(),
                   "discounting term structure handle is empty");

        results_.valuationDate = (*discountCurve_)->referenceDate();

        bool includeRefDateFlows =
            includeSettlementDateFlows_ ?
            *includeSettlementDateFlows_ :
            Settings::instance().includeReferenceDateCashFlows();

        results_.value = CashFlows::npv(arguments_.cashflows,
                                        **discountCurve_,
                                        includeRefDateFlows,
                                        results_.valuationDate,
                                        results_.valuationDate);

        // a bond's cashflow on settlement date is never taken into account
        results_.settlementValue = CashFlows::npv(arguments_.cashflows,
                                                  **discountCurve_,
                                                  false,
                                                  arguments_.settlementDate,
                                                  arguments_.settlementDate);
    }

}
