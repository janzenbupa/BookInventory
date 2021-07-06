USE [BookInventory]
GO

/****** Object:  StoredProcedure [dbo].[InsertAuthor]    Script Date: 7/5/2021 9:19:53 PM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE [dbo].[InsertAuthor]
	-- Add the parameters for the stored procedure here
	@firstName nvarchar(35),
	@lastName nvarchar(35)
AS
BEGIN
	INSERT INTO [dbo].[Authors](
		FirstName,
		LastName
	)
	VALUES(
		@firstName,
		@lastName
	)
END
GO
