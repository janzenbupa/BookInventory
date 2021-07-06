USE [BookInventory]
GO

/****** Object:  Table [dbo].[Authors]    Script Date: 7/5/2021 9:15:44 PM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Authors](
	[Id] [bigint] IDENTITY(1,1) NOT NULL,
	[FirstName] [nvarchar](20) NULL,
	[LastName] [nvarchar](20) NULL
) ON [PRIMARY]
GO
