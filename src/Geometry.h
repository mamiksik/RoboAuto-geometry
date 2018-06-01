//
// Created by Martin Miksik on 30/05/2018.
//

#pragma once

namespace GeometryMath {

	template < class T1, class T2 >
	struct Container
	{
		static double distance( const T1&, const T2& );


		static bool contains( const T1&, const T2& );
	};

	template < typename Derived >
	class DistanceTrait
	{
	protected:
		DistanceTrait( ) = default;

	public:
		template < class T >
		double distance( const T& object ) const
		{
			return GeometryMath::Container < Derived, T >::distance( static_cast<const Derived&>(*this), object );
		}
	};

	template < typename Derived >
	class ContainsTrait
	{
	protected:
		ContainsTrait( ) = default;

	public:
		template < typename T >
		bool contains( const T& object ) const
		{
			return GeometryMath::Container < Derived, T >::contains( static_cast<const Derived&>(* this), object );
		}
	};

};